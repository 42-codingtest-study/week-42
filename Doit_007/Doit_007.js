//문제: Doit_007
//0. 문제 이해 : N개의 숫자들 중 2개를 골라 합이 M이 되는 경우의 수 찾기
//1. 시간 복잡도 확인: 2초 -> 2억 연산, 15000개 중 M은 최대 1000만 (사실 숫자가 최대 10만이라 20만 이상의 수는 결과 값이 0), 이중 for문으로 구한다면 O(N^2)이라 최대 2억2500만이라 아쉽게 불가능 -> O(NlogN) 또는 O(N) 으로 해결 필요
//2. 적용 알고리즘 확인: 투 포인터(양쪽 끝의 left,right), 정렬
//3. 맞는 자료구조 확인: 배열
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [N, M] = [+input[0], +input[1]];
    const arr = input[2]
        .split(" ")
        .map(Number)
        .sort((a, b) => a - b);
    let startIndex = 0;
    let endIndex = N - 1;
    let result = 0;

    while (startIndex < endIndex) {
        if (arr[startIndex] + arr[endIndex] === M) {
            result++;
            startIndex++;
            endIndex--;
        } else if (arr[startIndex] + arr[endIndex] < M) {
            startIndex++;
        } else if (arr[startIndex] + arr[endIndex] > M) {
            endIndex--;
        }
    }
    console.log(result);
}
