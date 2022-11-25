def create_segment_tree(start_index, end_index, tree_node):
        if(start_index==end_index):
                tree[tree_node] = s[start_index]
                return
        # mid = start_index + (end_index-start_index)//2
        mid = (start_index+end_index)//2
        create_segment_tree(start_index, mid, 2*tree_node)
        create_segment_tree(mid+1, end_index, 2*tree_node+1)
        tree[tree_node] = tree[2*tree_node]+tree[2*tree_node+1]

def update_segment_tree(start_index, end_index, tree_node, update_index, update_value):
        if(start_index==end_index):
                print('yes', tree_node, update_index, update_value)
                tree[tree_node] = update_value
                s[update_index] = update_value
                return

        # mid = start_index+(end_index-start_index)//2
        mid = (start_index+end_index)//2
        if(mid>update_index):
                update_segment_tree(start_index, mid, 2*tree_node, update_index, update_value)
        else:
                update_segment_tree(mid+1, end_index, 2*tree_node+1, update_index, update_value)
        tree[tree_node] = tree[2*tree_node]+tree[2*tree_node+1]

def query_segment_tree(start_index, end_index, tree_node, left, right):
        #completely outside
        if(left>end_index or right<start_index):
                return ''
        #completely inside
        if(start_index>=left and right>=end_index):
                return tree[tree_node]
        
        #partially inside
        # mid = start_index+(end_index-start_index)//2
        mid = (start_index+end_index)//2
        left_subtree  = query_segment_tree(start_index, mid, 2*tree_node, left, right)
        right_subtree = query_segment_tree(mid+1, end_index, 2*tree_node+1, left, right)
        return left_subtree+right_subtree
        

for _ in range(1):
        n, q = map(int, input().split())
        s = list(input())
        tree = ['-1' for _ in range(4*n)]
        create_segment_tree(0, n-1, 1)
        for _ in range(q):
                query = list(map(int, input().split()))
                if query[0]==1:
                        update_index = query[1]-1
                        update_value = '1' if s[update_index]=='0' else '0'
                        update_segment_tree(0, n-1, 1, update_index, update_value)
                        print(*tree)
                else:
                        left, right = query[1]-1, query[2]-1
                        ans = query_segment_tree(0, n-1, 1, left, right)
                        print(int(ans, 2))