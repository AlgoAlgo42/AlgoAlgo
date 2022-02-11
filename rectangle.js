function solution(w, h) {
	var answer = 0;
	// 시간 초과를 방지
	if (w <= 1 || h <= 1) return 0;
	for (let i = 0; i < w; ++i) {
		answer += parseInt((h * i) / w);
		// 부동소수점이라 나눌경우 정밀도가 떨어짐으로 곱하기 부터 해야 함.
	}
	return answer * 2;
}
// 그 외 흥미로웠던 풀이는 최대공약수를 구해서 푸는 방법
// 조각나는 사각형의 갯수 = w + h - gcd;
