template <typename T>
int descer(T *v, int n, int i) {
  int left_child, right_child, largest;
  bool flag = true;
  while(flag){
    largest = i; // the largest it's dad
    left_child = 2*i + 1; // left child
    right_child = left_child+1; // right child
    if(left_child < n && v[left_child] > v[i] && v[left_child] >= v[right_child]) largest = left_child; // if left child exists and he its largest tha him dad, now, left child is the largest
    if(right_child < n && v[right_child] > v[i] && v[right_child] >= v[left_child]) largest = right_child;
    swap(v[i], v[largest]);
    flag = (i != largest);
		i = largest;
  } return i;
 }

template <typename T>
void heapsort (T *v, int n) {
  int levels = log2(n); // number of levels in the tree, n = number of nodes total
  int n_leaf_nodes = pow(2, (levels-1) + 1) - 1; // number of non- leaf nodes.
  for(int i = n_leaf_nodes - 1; i >= 0; i--) {
    	descer(v, n, i);
  }
  for(int i = n-1; i >= 0; i--) {
    if(v[0] > v[i]) {
      swap(v[0], v[i]);
      descer(v, i, 0);
    }
  }	
}
