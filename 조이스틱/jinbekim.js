function countVerticalMove(alphabet) {
	const asciiNum = alphabet.charCodeAt(0);
	if (asciiNum > 77) return 91 - asciiNum;
	else return asciiNum - 65;
}

function solution(name) {
	var answer = 0;
	const nameLength = name.length;
	let next,
		horizonMove = nameLength - 1;
	for (let idx = 0; idx < nameLength; ++idx) {
		answer += countVerticalMove(name[idx]);
		next = idx + 1;
		while (next < nameLength && name[next] === 'A') next++;
		const backward = nameLength - next;
		horizonMove = Math.min(
			horizonMove,
			idx + backward + Math.min(idx, backward)
		);
	}
	answer += horizonMove;
	return answer;
}
