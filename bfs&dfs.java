
public class Nodeinfo{
	private List<List<Node>> graphList;

	public class Node{
		char nodeName;
		boolean isVisited;
		public Node (char name){
			nodeName = name;
		}

		public boolean isVisited(){
			return isVisited;
		}

		public void setVisited (boolean visited){
			isVisited = visited;
		}

		public int getNodeName(){
			return nodeName;
		}
	}
    
    public void initNode(){
		for (List < Node > list : graphList) {
			for (Node node : list) {
				node.setVisited(false);
			}
		}
    }

    void onCreateGraph(){
<<<<<<< Updated upstream
        Node a = new Node('A');
        Node b = new Node('B');
        Node c = new Node('C');
        Node d = new Node('D');
        Node e = new Node('E');
        Node f = new Node('F');
=======
        Node a = new Node('a');
        Node b = new Node('b');
        Node c = new Node('c');
        Node d = new Node('d');
        Node e = new Node('e');
        Node f = new Node('f');
>>>>>>> Stashed changes

        List<Node> aList = Arrays.asList(a, b, c, d);
        List<Node> bList = Arrays.asList(b, a, e, f);
        List<Node> cList = Arrays.asList(c, a, f);
        List<Node> dList = Arrays.asList(d, a);
        List<Node> eList = Arrays.asList(e, b);
        List<Node> fList = Arrays.asList(f, b, c);

        graphList = Arrays.asList(aList, bList, cList, dList, eList, fList);
        initNode();
    }

    public void bfs(Node root){//广度搜索

    	onCreateGraph();
    	Queue<Node> q = new LinkedList<Node>();
    	root.setVisited(true);
    	q.add(root);

    	while (q.isEmpty()==false){
    		Node node = q.peek();
    		Node child = getAdjacentNode(node);
    		if(child != nil){
    			child.isVisited = true;
    			q.add(child);
    		}else{
    			q.remove();
    		}
    	}
    }

    public void dfs(Node root){//深度搜索

    	onCreateGraph();
    	Stack s = new Stack();
    	root.setVisited(true);
    	s.push(root);
    	while (s.isEmpty()==false){
    		Node node = s.peek();
    		Node child = getAdjacentNode(node);
    		if(child != nil){
    			child.isVisited = true;
    			s.push(child);
    		}else{
    			s.pop();
    		}
    	}
    }


    public Node getAdjacentNode (Node node){
    	Node tmp = null;

    	for (List<Node> list : graphList ) {
    		Node firstNode = list.get(0);
    		if(firstNode.getNodeName() == n.getNodeName()){
    			for (Node node : list) {
    				if(node.isVisited() == false){
    					tmp = node;
    					break;
    				}
    			}
    		}
    		break;
    	}
    	return tmp;
    }

}

