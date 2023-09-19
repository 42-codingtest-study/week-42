//문제: Doit_002
//0. 문제 이해 : 과목 점수들중 최댓값을 기준으로 (각 점수 / 최대 점수 * 100)들의 평균을 구해라
//1. 시간 복잡도 확인: 2초 => 2억 연산 (N이 최대 1000 => 최댓값 연산 1000회, 총합 구하는 연산)
//2. 적용 알고리즘 확인: 배열
//3. 맞는 자료구조 확인: 배열
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const N = +input[0]; // + 붙이면 바로 숫자로 바뀜
    const arr = input[1].split(" ").map(Number); // 숫자들 배열
    const M = Math.max(...arr); // 최댓값
    const sum = arr.reduce((acc, curr) => {
        return acc + curr;
    }, 0); // arr 총합
    console.log(((sum / M) * 100) / N); // 각각의 연산을 할 필요없이 총합을 구하고 연산 후 N만큼 나눠주면 된다.
}
