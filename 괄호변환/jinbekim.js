function rever(str) {
	let ret = '';

	for (let i = 0, len = str.length; i < len; ++i) {
		if (str[i] === '(') ret += ')';
		else ret += '(';
	}
	return ret;
}

function solution(str) {
	if (str === '') return ''; // 빈 문자열일 경우

	const stack = [];
	let rightPair = false;
	let balence = 0;

	let u, v;

	for (let i = 0, length = str.length; i < length; ++i) {
		// pair가 맞지 않는 문자열이 들어오면 터짐. 바깥에 변수로 체크해서 해주면 좋을듯.
		if (str[i] === '(') {
			balence += 1;
			stack.push(str[i]);
		}
		if (str[i] === ')') {
			balence -= 1;
			stack.pop();
		}
		if (balence === 0) {
			if (stack.length === 0) rightPair = true; // 나는 stack으로 짝을 맞췄지만 그냥 u 문자열의 처음과 끝만 맞으면 올바른 괄호일듯.
			u = str.slice(0, i + 1);
			v = str.slice(i + 1);
			break;
		}
	}
	if (rightPair) return u + solution(v);
	return '(' + solution(v) + ')' + rever(u.slice(1, -1));
}
