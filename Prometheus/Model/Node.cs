using System;

namespace Prometheus.Model
{
	public class Node
	{
		string name;

		public string Name
		{
			get { return name; }
			set { name = value; }
		}

		public Node(string name)
		{
			Name = name;
		}
	}
}

