//문제: Doit_006
//0. 문제 이해 : N을 연속된 자연수의 합으로 나타낼 수 있는 경우의 수를 출력
//1. 시간 복잡도 확인: 2초 -> 2억 연산  N-> 1000만 1~N까지 최대 N번 순회 하면서 경우의 수를 생각하면 O(N^2)이 100조 연산, O(NlogN) -> 7000만, O(N) -> 1000만
//2. 적용 알고리즘 확인: O(N) 으로 연속된 수열 순회할 수 있는 투포인터
//3. 맞는 자료구조 확인: 배열 // 틀림 배열도 필요없음 배열 굳이 만드니까 메모리초과
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const N = +input[0];
    // const arr = Array.from(Array(N), (i, idx) => (i = idx + 1)); // 1~N 배열 생성 // 필요없음
    let start_idx = 0;
    let end_idx = 0; // start, end 가 같이 시작
    let sum = 0;
    let result = 0;

    while (start_idx < N) {
        // 종료 조건
        if (sum < N) {
            sum += end_idx + 1;
            end_idx++;
        } else if (sum >= N) {
            if (sum === N) result++;
            sum -= start_idx + 1;
            start_idx++;
        }
    }
    console.log(result);
}
