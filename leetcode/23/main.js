function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
  const pq = new MinPriorityQueue((node) => node.val);
  for (const node of lists) {
    if (node) pq.enqueue(node);
  }

  const head = new ListNode();
  let cur = head;

  while (!pq.isEmpty()) {
    const node = pq.dequeue();
    cur.next = node;
    cur = cur.next;
    if (node.next) pq.enqueue(node.next);
  }

  return head.next;
};
