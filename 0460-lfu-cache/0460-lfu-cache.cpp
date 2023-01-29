class LFUCache {
public:
  struct ListNode {
    int key;
    int val;
    int freq;
    ListNode *next;
    ListNode *prev;
  };
  
  LFUCache(int capacity) : capacity_(capacity), size_(0), lowestFreq_(0) {
  }
  
  int get(int key) {
    auto itor = keyLut_.find(key);
    if (itor == keyLut_.end())
      return -1;
    int ret = itor->second->val;
    promote(itor->second);
    return ret;
  }
  
  void put(int key, int value) {
    if (!capacity_)
      return;
    auto itor = keyLut_.find(key);
    if (itor == keyLut_.end()) {
      // New key, need to check capacity
      ListNode * node = 0;
      if (capacity_ == size_) {
        // Full capacity, need to kill some old node and recycle it as new
        auto fItor = freqLut_.find(lowestFreq_);
        node = fItor->second.first;
        if (node->next) {
          fItor->second.first = node->next;
          node->next->prev = 0;
        }
        else
          freqLut_.erase(fItor);
        keyLut_.erase(node->key);
      }
      // If nothing recycled, increase size.
      else {
        node = new ListNode();
        ++size_;
      }
      node->key = key;
      node->val = value;
      node->freq = 1;
      node->next = 0;
      auto fItor = freqLut_.find(1);
      if (fItor == freqLut_.end()) {
        freqLut_.insert({1, {node, node}});
        node->prev = 0;
      }
      else {
        fItor->second.second->next = node;
        node->prev = fItor->second.second;
        fItor->second.second = node;
      }
      keyLut_.insert({key, node});
      lowestFreq_ = 1;
    }
    else {
      itor->second->val = value;
      promote(itor->second);
    }
  }

private:
  void promote(ListNode * node) {
    // Remove node from freq list
    auto itor = freqLut_.find(node->freq);
    if (itor->second.first == node) {
      // The node is at the beginning of the list
      if (node->next) {
        // List length is more than 1
        itor->second.first = node->next;
        node->next->prev = 0;
      }
      else {
        // List length is 1
        freqLut_.erase(itor);
        if (lowestFreq_ == node->freq)
          ++lowestFreq_;
      }
    }
    else if (itor->second.second == node) {
      // The node is at the end of the list
      itor->second.second = node->prev;
      node->prev->next = 0;
    }
    else {
      // The node is in the middle of the list
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    
    // Add node to the end of freq+1 list
    node->next = 0;
    itor = freqLut_.find(++node->freq);
    if (itor == freqLut_.end()) {
      // Start a new freq list
      freqLut_.insert({node->freq, {node, node}});
      node->prev = 0;
    }
    else {
      // Append to an existing freq list
      itor->second.second->next = node;
      node->prev = itor->second.second;
      itor->second.second = node;
    }
  }
  
  // freq to the head and tail of the list of nodes in most recent access order
  std::unordered_map<int, std::pair<ListNode *, ListNode *>> freqLut_;
  // key to the node
  std::unordered_map<int, ListNode *> keyLut_;
  int capacity_;
  int size_;
  int lowestFreq_;
};