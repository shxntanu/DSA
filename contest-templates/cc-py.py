# cook your dish here
import sys
import math
from collections import Counter
import heapq
input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
def gen_dict(lst):
    return dict(Counter(lst))
    
MOD = 1e9 + 7
 
def solve():
    pass
    
if __name__ == "__main__": 
    t = int(input())
    for i in range(t):
        solve()
