function solution(record) {
	var answer = [];
	const nickName = new Map();
	const eventList = [];

	record.forEach((event) => {
		const split = event.split(' ');
		switch (split[0]) {
			case 'Enter':
				eventList.push([split[0], split[1]]);
				nickName.set(split[1], split[2]);
				break;
			case 'Leave':
				eventList.push([split[0], split[1]]);
				break;
			case 'Change':
				nickName.set(split[1], split[2]);
				break;
		}
	});
	eventList.forEach((key) => {
		const event = key[0];
		const name = nickName.get(key[1]);
		switch (event) {
			case 'Enter':
				answer.push(name + '님이 들어왔습니다.');
				break;
			case 'Leave':
				answer.push(name + '님이 나갔습니다.');
				break;
		}
	});
	return answer;
}
