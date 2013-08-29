using System.Collections.Generic;

namespace Prometheus.Model
{
	public class Table : Node
	{
		SortedSet<Node> nodes;

		public Table(string name) : base(name)
		{
		}
	}
}

