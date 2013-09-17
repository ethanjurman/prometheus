using System;
using System.Collections.Generic;

namespace Prometheus.Model
{
	public abstract class Node
	{
		string name;
        bool selected;
        Node parent;
        NodeDatabase db;

        protected Node(string name, Node parent, NodeDatabase db, bool selected = false)
		{
			Name = name;
            Parent = parent;
            Db = db;
			Selected = selected;
            db.Insert(this);
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

        public NodeDatabase Db
        {
            get { return db; }
            set { db = value; }
        }

		public bool Selected
		{
			get { return selected; }
			set { selected = value; }
		}
	}
}

