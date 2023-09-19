//문제: Doit_005
//0. 문제 이해 :  연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성
//1. 시간 복잡도 확인: 1초 -> 1억 N-> 100만 수열
//2. 적용 알고리즘 확인: 누적합을 사용한 구간합, 나눗셈 계산
//3. 맞는 자료구조 확인: bigInt 써야할까? number 범위 < 10^16 이상 => ㄱㅊ, 배열로 저장
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [N, M] = input.shift().split(" ").map(Number);
    const arr = input.shift().split(" ").map(Number); // 배열 숫자 M으로 나눠서 arr에 저장
    const cum_sum_arr = [arr[0] % M]; // 누적 합 배열 생성 , 첫 값 저장
    const check_num = Array.from(Array(M), () => 0); // 각 숫자의 개수 확인 배열 생성
    check_num[arr[0] % M]++; // 첫 값 저장
    let answer = 0;
    for (let i = 1; i < N; i++) {
        let n = (cum_sum_arr[i - 1] + arr[i]) % M;
        check_num[n]++; // 개수 증가
        cum_sum_arr.push(n); // 누적 합 저장
    }
    answer += check_num[0]; // 누적 합 저장 값이 0 이라는 것은 0~i까지의 누적 합이 0 이라는 것이기에 0의 개수만큼 answer에 추가
    check_num.forEach((e) => {
        if (e) answer += (e * (e - 1)) / 2; // 누적합 나머지 배열의 값이 같다는 것은 구간합의 나머지가 0이되는 것이므로 같은 숫자 들의 조합 갯수를 answer에 추가
    });
    console.log(answer);
}
