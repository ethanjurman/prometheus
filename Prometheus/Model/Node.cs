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
			set {
                if (value.Length > 255)
                    throw new FormatException("length of name is greater than 255 characters.");
                name = value;
            }
		}

        public Node Parent
        {
            get { return parent; }
            set {
                if (parent == this)
                    throw new ArgumentException("Node " + this.Name + " cannot be a parent of itself.");
                parent = value; 
            }
        }

		public bool Selected
		{
			get { return selected; }
			set { selected = value; }
		}
	}
}

