//문제: Doit_008
//0. 문제 이해 : 수열 중 본인의 수를 나머지 수들 두개의 합으로 나타낼 수 있다는 수의 개수
//1. 시간 복잡도 확인: 2초 -> 2억 연산 N은 최대 2000 N까지의 이중포문을 N번 돌면 O(N^3) => 80억 안됨 최대 O(N^2)안에서 해결 (각 숫자마다 확인하는 과정 O(N))
//2. 적용 알고리즘 확인: 투포인터 (O(N))
//3. 맞는 자료구조 확인: 배열
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const N = +input.shift();
    const arr = input
        .shift()
        .split(" ")
        .map(Number)
        .sort((a, b) => a - b); // 정렬된 숫자 배열
    let count = 0; // 결과값
    arr.forEach((e, idx) => {
        // 배열 메서드를 활용해 for문을 도는데 index를 같이 확인할 수 있다.
        let startIndex = 0;
        let endIndex = N - 1;

        while (startIndex < endIndex) {
            if (arr[startIndex] + arr[endIndex] === e) {
                if (startIndex === idx) startIndex++; // 본인 index라면 스킵
                else if (endIndex === idx) endIndex--; // 본인 index라면 스킵
                else {
                    count++;
                    break; // 좋은 수라면 더 확인할 필요없이 break
                }
            } else if (arr[startIndex] + arr[endIndex] < e) {
                startIndex++; //합이 작다면 startIndex증가 아니면 endIndex 감소
            } else {
                endIndex--;
            }
        }
    });
    console.log(count);
}
