import UIKit

class BFSDFSSearch : NSObject{
    
    public class Node {
        var isVisited : Bool
        var nodeName : String?
        init(name : String) {
            isVisited = false
            nodeName = name
        }
        func setVisited(visited : Bool) -> Void {
            self.isVisited = visited;
        }
        func getVisited() -> Bool {
            return isVisited
        }
        func getNodeName() -> String {
            return nodeName!
        }
    }
    
    var graghList : Array<Any>?
    
    func createGraph() -> Void {
        let aNode = Node(name: "a")
        let bNode = Node(name: "b")
        let cNode = Node(name: "c")
        let dNode = Node(name: "d")
        let eNode = Node(name: "e")
        let fNode = Node(name: "f")
        
        let aList : [Node] = [aNode,bNode,cNode,dNode]
        let bList : [Node] = [bNode,aNode,eNode,fNode]
        let cList : [Node] = [cNode,aNode,fNode]
        let dList : [Node] = [dNode,aNode]
        let eList : [Node] = [eNode,bNode]
        let fList : [Node] = [fNode,aNode,bNode]
        
        graghList = [aList,bList,cList,dList,eList,fList]
        
        resetNodesData()
        bfs_search(root: aNode)
        
        resetNodesData()
        dfs_search(root: aNode)
    }
    
    
    func bfs_search(root : Node) -> Void {
        var queue : Array<Node>?
        root.setVisited(visited: true)
        queue?.append(root)
        
        while queue?.count != 0 {
            let node = queue?.first
            let child = getAdjacentNode(aNode: node!)
            if (child != nil) {
                child?.setVisited(visited: true)
                queue?.append(child!)
            }else{
                queue?.removeFirst()
            }
        }
    }
    
    func dfs_search(root : Node) -> Void {
        var stack : Array<Node>?
        root.setVisited(visited: true)
        stack?.append(root)
        
        while stack?.count != 0 {
            let node = stack?.first
            let child = getAdjacentNode(aNode: node!)
            if (child != nil){
                child?.setVisited(visited: true)
                stack?.append(child!)
            }else{
                stack?.removeLast()
            }
        }
        
    }
    
    func getAdjacentNode(aNode : Node) -> Node? {
        var tmp : Node? = nil
        for arr in graghList! {
            let firstNode = (arr as? Array<Any>)?.first as? Node
            if firstNode?.getNodeName() == aNode.getNodeName(){
                for node in (arr as? Array<Any>)!  {
                    if (node as? Node)?.getVisited() == false{
                        tmp = node as? Node
                        break
                    }
                }
                break;
            }
        }
        return tmp
    }
    
    func resetNodesData() -> Void {
        for arr in graghList! {
            for node in (arr as? Array<Any>)!  {
                (node as? Node)?.setVisited(visited: false)
            }
        }
    }
}