using System.Collections.Generic;

namespace Prometheus.Model
{
	public class Table : Node
	{
        SortedSet<EvalNode> evalNodes;
        SortedSet<Table> tables;
        SortedSet<RuleNode> ruleNodes;
        string queryTag;

		public Table(string name, Node parent, NodeDatabase db) : base(name, parent, db)
		{
            EvalNodes = new SortedSet<EvalNode>();
            Tables = new SortedSet<Table>();
            RuleNodes = new SortedSet<RuleNode>();
		}

        public string QueryTag
        {
            get { return queryTag; }
            set { queryTag = value; }
        }

		public SortedSet<EvalNode> EvalNodes
		{
			get { return evalNodes; }
			set { evalNodes = value; }
		}

		public SortedSet<Table> Tables
		{
			get { return tables; }
			set { tables = value; }
		}

		public SortedSet<RuleNode> RuleNodes
		{
			get { return ruleNodes; }
			set { ruleNodes = value; }
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
            foreach (Node node in Db.ParentQuery(QueryTag))
            {
                if (node is Table)
                {
                    if (flat)
                        queryNodesFlat((Table)node);
                    else
                        Tables.Add((Table)node);
                }
                else if (node is RuleNode)
                    RuleNodes.Add((RuleNode)node);
                else if (node is EvalNode)
                    EvalNodes.Add((EvalNode)node);
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
                RuleNodes.Add(node);
            foreach (EvalNode node in table.evalNodes)
                EvalNodes.Add(node);
        }
	}
}

