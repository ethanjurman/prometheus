using System;

namespace Prometheus.Model
{
	public abstract class Node
	{
		string name;
        bool selected;
        Node parent;

        protected Node(string name, ref Node parent, bool selected = false)
		{
			Name = name;
            Parent = parent;
			Selected = selected;
		}
		
		public string Name
		{
			get { return name; }
			set { name = value; }
		}

        public Node Parent
        {
            get { return parent; }
            set { parent = value; }
        }

		public bool Selected
		{
			get { return selected; }
			set { selected = value; }
		}
	}
}

