using System;

namespace Prometheus.Model
{
	public class RuleNode : Node
	{
		string rule;
		int priority;

		public RuleNode(string name = "Default Rule") : base(name)
		{
			priority = 0;
			rule = "";
		}

		public bool parseRule()
		{
			return false;
		}
	}
}

