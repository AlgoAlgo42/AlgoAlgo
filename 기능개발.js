function solution(progresses, speeds) {
	const answer = [];
	let day = 0;
	let numOfEndWork = 0;
	const progressesLen = progresses.length;

	while (numOfEndWork < progressesLen) {
		let count = 0;
		for (let i = numOfEndWork; i < progressesLen; i++) {
			if (progresses[i] + speeds[i] * day >= 100) count++;
			else break;
		}
		if (count !== 0) {
			answer.push(count);
			numOfEndWork += count;
		}
		day++;
	}
	return answer;
}
