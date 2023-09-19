//문제: Doit_001
//0. 문제 이해 : 공백없이 들어온 숫자들의 총합을 구해라
//1. 시간 복잡도 확인: 1초 -> 1억 연산
//2. 적용 알고리즘 확인: 배열
//3. 맞는 자료구조 확인: 배열
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const result = input[1] // input의 두번째 줄
        .split("")
        .map(Number) // 배열 요소 값들 Number로 변환
        .reduce((acc, curr) => {
            return acc + curr;
        }, 0);
    // reduce 는 js의 배열 사용자 정의 콜백 함수
    //acc는 이전 콜백 함수 결과로 리턴된 값을 저장하는 변수
    //curr은 현재 루프를 돌고있는 배열의 요소값
    //reduce를 통해 배열의 총합을 구할 수 있음
    console.log(result);
}
