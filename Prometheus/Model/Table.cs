using System.Collections.Generic;

namespace Prometheus.Model
{
	public class Table : Node
	{
		SortedSet<Node> nodes;
        SortedSet<RuleNode> ruleNodes;
        string queryTag;

		public Table(string name, ref Node parent) : base(name, ref parent)
		{
		}

        public string QueryTag
        {
            get { return queryTag; }
            set { queryTag = value; }
        }
	}
}

