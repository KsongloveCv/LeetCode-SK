/*
*  Author:      Sker <ksong666@163.com>
*  File:        tle_bruteforce_n2.cpp
*  Descripton:  创建一个新链表，使用变量来跟踪进位，并从包含最低有效位的表头开始模拟逐位相加的过程。
*/
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        target = ListNode(0)   # 作为根节点的引用
        p = target
        add = 0    # 作为上一次相加是否需要进1的依据
        while l1 and l2:
            p.next = ListNode((l1.val+l2.val+add)%10)
            add = (l1.val+l2.val+add)//10
            p, l1, l2 = p.next, l1.next, l2.next
        l1 = l1 if l1 else l2
        while add:
            if l1:
                p.next = ListNode((l1.val+add)%10)
                add = (l1.val+add)//10
                p, l1 = p.next, l1.next
            else:
                p.next = ListNode(add)
                p = p.next
                break
        p.next = l1 
        
        return target.next
