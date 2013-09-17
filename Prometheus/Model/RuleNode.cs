using System;

namespace Prometheus.Model
{
	public class RuleNode : Node
	{
		string rule;
		int priority;

		public RuleNode(string name, Node parent, NodeDatabase db) : base(name, parent, db)
		{
			Priority = 0;
			Rule = "";
		}

        //stub
		public bool parseRule()
		{
            if (rule.Length == 0 || rule == null)
                throw new FormatException("Cannot execute an empty rule.");
            return true;
		}

		// Properties
		public string Rule
		{
			get { return rule; }
			set { rule = value; }
		}

		public int Priority
		{
			get { return priority; }
			set { priority = value; }
		}
	}
}

