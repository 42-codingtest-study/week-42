//문제: Doit_010
//0. 문제 이해 : 크기가 정해진 구간의 최솟값을 출력해라
//1. 시간 복잡도 확인: 2.4초 ->2억4천만 연산, 500만개 이중 포문으로 해결할 경우 최대 250만^2 => 6조...ㅋㅋ
//2. 적용 알고리즘 확인:  슬라이딩 윈도우
//3. 맞는 자료구조 확인: 순서마다 앞으로 뻬야하고 조건에 맞게 뒤에서 넣고 빼고를 반복해야함으로 deque을 쓰는게 적당할 것으로 파악된다.

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

class Deque {
    constructor() {
        this.arr = [];
        this.head = 0;
        this.tail = 0;
    }
    push_front(item) {
        if (this.arr[0]) {
            for (let i = this.arr.length; i > 0; i--) {
                this.arr[i] = this.arr[i - 1];
            }
        }
        this.arr[this.head] = item;
        this.tail++;
    }
    push_back(item) {
        this.arr[this.tail++] = item;
    }
    pop_front() {
        if (this.head >= this.tail) {
            return null;
        } else {
            const result = this.arr[this.head++];
            return result;
        }
    }
    pop_back() {
        if (this.head >= this.tail) {
            return null;
        } else {
            const result = this.arr[--this.tail];
            return result;
        }
    }
    isEmpty() {
        return this.head >= this.tail;
    }
}

solution(input);
function solution(input) {
    const [N, L] = input.shift().split(" ").map(Number);
    const arr = input.shift().split(" ").map(Number);

    let answer = "";
    const deque = new Deque(); // 연결리스트 deque으로 구현해야한다. 배열로 구현했다가 pop_front()가 O(N)이라 시간초과 걸려서 개빡침    pop_front O(N)으로 할 수 있는 연결리스트로 새로 구현

    arr.forEach((e, idx) => {
        // 값 하나하나씩 e는 값 idx는 인덱스
        // console.log(deque);
        if (!deque.isEmpty() && deque.arr[deque.head][1] < idx - L + 1) {
            deque.pop_front(); // deque이 비어있지 않고 맨 앞 값의 인덱스가 빠질 순서ㄱ라면 popfront한다
        }
        while (!deque.isEmpty() && deque.arr[deque.tail - 1][0] > e) {
            deque.pop_back(); // deque에 넣을 때 deque의 tail값이 넣을 값보다 크면 다 빼준다.
        }
        deque.push_back([e, idx]); // 그 뒤에 넣어준다.
        answer += deque.arr[deque.head][0] + " "; // 매번 head값이 최솟값
        if (idx % 10000 === 0) {
            process.stdout.write(answer);
            answer = "";
        }
    });
    console.log(answer.trim());
}
