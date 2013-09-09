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
        /// method to query nodes into this table
        /// </summary>
        /// <param name="flat">
        /// if elements should be depth one, then
        /// flat should be true
        /// </param>
        public void queryNodes(bool flat = false)
        {
            foreach (Node node in Db.ParentQuery(queryTag))
            {
                if (node is Table)
                {
                    if (flat)
                        queryNodesFlat((Table)node);
                    else
                        tables.Add((Table)node);
                }
                else if (node is RuleNode)
                    ruleNodes.Add((RuleNode)node);
                else if (node is EvalNode)
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

