function solution(id_list, report, k) {
	var answer = {};
	var history = {};
	id_list.forEach((who) => { // id마다 신고 결과를 저장할 set을 만든다.
		history[who] = new Set();
		answer[who] = 0;
	});
	for (const vote of report) { // 신고 결과를 저장한다.
		const detail = vote.split(' ');
		history[detail[1]].add(detail[0]);
	}
	for (const prop in history) {
		if (history[prop].size >= k) { // 신고 결과가 k보다 크면 신고 결과를 저장한다.
			history[prop].forEach((val) => {
				answer[val] += 1; // 신고 결과를 반환할 갯수를 센다.
			});
		}
	}
	var ret = [];
	for (const prop in answer) {
		ret.push(answer[prop]); // 반환할 갯수를 저장하는 배열을 만든다.
	}
	return ret;
}
