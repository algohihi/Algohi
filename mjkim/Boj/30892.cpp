/* 배열 인덱스(pos)로 "아직 먹지 않은 상어"와 "먹을 수 있는 후보" 구분
정렬된 배열에서 pos를 앞으로 이동하면서 t보다 작은 상어를 힙에 넣고, 힙에서 가장 큰 상어 먹기

1. 입력 및 정렬
상어 크기 배열 arr을 오름차순 정렬합니다.

2. 인덱스 변수 관리
pos : 아직 먹지 않은 상어 중에서, 현재 몸집 t보다 작은 상어의 첫 인덱스(= 먹을 수 있는 후보의 끝)

"먹을 수 있는 상어 후보"는 arr[pos] < t인 모든 arr[pos]입니다.

이 후보들을 최대 힙(배열)로 관리해서, 매번 가장 큰 상어를 먹습니다.

3. 반복문
K번 반복:

아직 먹지 않은 상어 중에서 arr[pos] < t인 모든 상어를 힙에 push

힙이 비어 있으면 종료 (더 이상 먹을 수 없음)

힙에서 pop하여 가장 큰 상어를 먹고, t에 더함

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000

// 오름차순 정렬 함수
int compare(const void* a, const void* b) 
{
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// 최대 힙 구현
long long heap[MAXN + 1];
int heap_size = 0;

void push(long long x) 
{
    int i = ++heap_size;
    while (i != 1 && heap[i / 2] < x) 
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

long long pop() 
{
    long long ret = heap[1];
    long long temp = heap[heap_size--];
    int parent = 1, child = 2;
    while (child <= heap_size) 
    {
        if (child < heap_size && heap[child] < heap[child + 1])
            child++;
        if (temp >= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return ret;
}

int main() 
{
    int n, k;
    long long t;
    long long arr[MAXN];

    scanf("%d %d %lld", &n, &k, &t);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // 1. 오름차순 정렬
    qsort(arr, n, sizeof(long long), compare);
     
    int pos = 0; // 아직 먹지 않은 상어 중 가장 작은 것의 인덱스  ( 현재 몸집 t보다 작은 상어의 첫 인덱스 )

    // 2. 최대 k번 반복
    for (int i = 0; i < k; i++) {
        // 현재 t로 먹을 수 있는 상어를 모두 힙에 push
        while (pos < n && arr[pos] < t) {
            push(arr[pos]);
            pos++;
        }
        // 먹을 수 있는 상어가 없으면 종료
        if (heap_size == 0) break;
        // 가장 큰 상어 먹기
        t += pop();
    }

    printf("%lld\n", t);
    return 0;
}