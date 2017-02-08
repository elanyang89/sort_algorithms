
#import <Foundation/Foundation.h>

@interface Node : NSObject 

@property (nonatomic,assign) BOOL isVisited;

@property (nonatomic,copy) NSString *name;

@end

@implementation Node

- (instancetype)initWithName:(NSString *)name{
    
    self = [super init];
    if(self){
        self.name = name;
    }
    return self;
}

@end


@interface BFSDFSSearch()

@property (nonatomic,retain) NSArray *graghList;

@end

@implementation BFSDFSSearch

- (void)createGraph{
    
    Node *a  = [[Node alloc] initWithName:@"a"];
    Node *b  = [[Node alloc] initWithName:@"b"];
    Node *c  = [[Node alloc] initWithName:@"c"];
    Node *d  = [[Node alloc] initWithName:@"d"];
    Node *e  = [[Node alloc] initWithName:@"e"];
    Node *f  = [[Node alloc] initWithName:@"f"];
    
    NSArray *aList = [NSArray arrayWithObjects:a,b,c,d,nil];
    NSArray *bList = [NSArray arrayWithObjects:b,a,e,f,nil];
    NSArray *cList = [NSArray arrayWithObjects:c,a,f,nil];
    NSArray *dList = [NSArray arrayWithObjects:d,a,nil];
    NSArray *eList = [NSArray arrayWithObjects:e,b,nil];
    NSArray *fList = [NSArray arrayWithObjects:f,a,b,nil];
    
    _graghList = [NSArray arrayWithObjects:aList,bList,cList,dList,eList,fList,nil];
    
    [self resetNodesData];
    [self bfs_search:a];//广度搜索
    
    [self resetNodesData];
    [self dfs_search:a];//深度搜索
}

- (void)bfs_search:(Node *)root{
    NSMutableArray *queue = [NSMutableArray array];
    root.isVisited = YES;
    [queue addObject:root];
    
    while (queue.count != 0) {
        Node *node = [queue objectAtIndex:0];
        Node *child = [self getAdjacentNode:node];
        if(child){
            child.isVisited = YES;
            [queue addObject:child];
        }else{
            [queue removeObjectAtIndex:0];
        }
    }
}

- (void)dfs_search:(Node *)root{

    NSMutableArray *stack = [NSMutableArray array];
    root.isVisited = YES;
    [stack addObject:root];
    
    while (stack.count != 0) {
        Node *node = [stack lastObject];
        Node *child = [self getAdjacentNode:node];
        if(child){
            child.isVisited = YES;
            [stack addObject:child];
        }else{
            [stack removeLastObject];
        }
    }
}

- (Node *)getAdjacentNode:(Node *)node{
    
    Node *tmp = nil;
    
    for (NSArray *list in _graghList) {
        Node *firstNode = (Node *)[list objectAtIndex:0];
        
        if([firstNode.name isEqualToString:node.name]){
            
            for (Node *node in list) {
                if(node.isVisited == NO){
                    tmp = node;
                    break;
                }
            }
            break;
        }
    }
    return tmp;
}

- (void)resetNodesData{
    for (NSArray *arr in _graghList) {
        for (Node *node in arr) {
            node.isVisited = NO;
        }
    }
}

@end