using System;

namespace Prometheus.Model
{
	public class Node
	{
		string name;
		bool selected;

		public Node(string name, bool selected = false)
		{
			Name = name;
			Selected = selected;
		}
		
		public string Name
		{
			get { return name; }
			set { name = value; }
		}

		public bool Selected
		{
			get { return selected; }
			set { selected = value; }
		}
	}
}

