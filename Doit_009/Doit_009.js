//문제: Doit_009
//0. 문제 이해 : 문자열의 P만큼의 부분문자열이 input[2]만큼의  A C G T를 가지는지 확인
//1. 시간 복잡도 확인: 2초 -> 2억연산 S가 100만 P도 최대 100만 가장 많은 연산은 P가 50만 일때 매번 일일히 체크한다면 O(50만^2) => 625억 연산 -> O(N^2)이면 안된다.
//2. 적용 알고리즘 확인: 포인터 하나로 옮겨가면서 매번 값을 구할 필요없이 변하는 정도만 바꾸는 -> 슬라이딩윈도우
//3. 맞는 자료구조 확인: 배열이면될듯
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [S, P] = input.shift().split(" ").map(Number);
    const arr = input.shift().split("");
    const num_limit_arr = input.shift().split(" ").map(Number);
    let num_limit = num_limit_arr.reduce((acc, curr) => acc + curr, 0);
    const check_limit = [0, 0, 0, 0];
    let cnt = 0;
    const next_dna = (k, check_limit) => {
        if (k === "A") {
            check_limit[0]++;
        } else if (k === "C") {
            check_limit[1]++;
        } else if (k === "G") {
            check_limit[2]++;
        } else if (k === "T") {
            check_limit[3]++;
        }
    }; // 들어오는 dna
    const prev_dna = (k, check_limit) => {
        if (k === "A") {
            check_limit[0]--;
        } else if (k === "C") {
            check_limit[1]--;
        } else if (k === "G") {
            check_limit[2]--;
        } else if (k === "T") {
            check_limit[3]--;
        }
    }; // 지나간 dna
    const check_ok = (check_limit, num_limit_arr) => {
        if (
            check_limit[0] >= num_limit_arr[0] &&
            check_limit[1] >= num_limit_arr[1] &&
            check_limit[2] >= num_limit_arr[2] &&
            check_limit[3] >= num_limit_arr[3]
        )
            return 1;
        else return 0;
    }; // 조건에 부합하는가 확인

    for (let i = 0; i < P; i++) {
        next_dna(arr[i], check_limit);
    }

    if (check_ok(check_limit, num_limit_arr)) cnt++;
    for (let i = P; i < S; i++) {
        prev_dna(arr[i - P], check_limit);
        next_dna(arr[i], check_limit);
        if (check_ok(check_limit, num_limit_arr)) cnt++;
    }
    console.log(cnt);
}
