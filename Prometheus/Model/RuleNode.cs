using System;

namespace Prometheus.Model
{
	public class RuleNode : Node
	{
		string rule, property;
		int priority;

		public RuleNode(string name = "Default Rule") : base(name)
		{
			Priority = 0;
			Rule = "";
			Property = "";
		}

		public RuleNode(string name, int priority, string property)
		{
			RuleNode(name);
			Priority = priority;
			Property = property;
		}

		public bool parseRule()
		{
			return false;
		}

		// Properties
		public string Rule
		{
			get
			{
				if(rule.Length == 0)
					throw new FormatException("Cannot execute an empty rule.");
				else
					return rule;
			}
			set { rule = value; }
		}

		public string Property
		{
			get { return property; }
			set { property = value; }
		}

		public int Priority
		{
			get { return priority; }
			set { priority = value; }
		}
	}
}

