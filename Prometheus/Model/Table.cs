using System.Collections.Generic;

namespace Prometheus.Model
{
	public class Table : Node
	{
        SortedSet<EvalNode> evalNodes;
        SortedSet<Table> tables;
        SortedSet<RuleNode> ruleNodes;
        string queryTag;

		public Table(string name, Node parent, Database db) : base(name, parent, db)
		{
            evalNodes = new SortedSet<EvalNode>();
            tables = new SortedSet<Table>();
            ruleNodes = new SortedSet<RuleNode>();
		}

        public string QueryTag
        {
            get { return queryTag; }
            set { queryTag = value; }
        }

        /// <summary>
        /// provides a way to fill tables with nodes from the database
        /// </summary>
        public void queryNodes()
        {
            foreach (Node node in Db.ParentQuery(queryTag))
            {
                if (node is Table)
                    tables.Add((Table)node);
                if (node is RuleNode)
                    ruleNodes.Add((RuleNode)node);
                if (node is EvalNode)
                    evalNodes.Add((EvalNode)node);
            }
        }

        /// <summary>
        /// alternative way to fill tables with nodes from the database
        /// (this method will allow sub-table nodes to be accessed at the
        /// first level... this will of course clutter the first level)
        /// </summary>
        public void queryNodesFlat()
        {
            foreach (Node node in Db.ParentQuery(queryTag))
            {
                if (node is Table)
                    tables.Add((Table)node);
                if (node is RuleNode)
                    ruleNodes.Add((RuleNode)node);
                if (node is EvalNode)
                    evalNodes.Add((EvalNode)node);
            }
        }

        /// <summary>
        /// recursive helper method for queryNodesFlat
        /// </summary>
        /// <param name="table"> the sub table to be 
        /// added to first level access</param>
        private void queryNodesFlat(Table table)
        {
            foreach (Table t in table.tables)
            {
                queryNodesFlat(t);
                tables.Add(t);
            }
            foreach (RuleNode node in table.ruleNodes)
                ruleNodes.Add(node);
            foreach (EvalNode node in table.evalNodes)
                evalNodes.Add(node);
        }
	}
}

