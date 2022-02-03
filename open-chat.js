function solution(record) {
	var answer = [];
	const nickName = new Map();
	const eventList = [];

	record.forEach((event) => {
		const [event, uid, nick] = event.split(' ');
		switch (event) {
			case 'Enter':
				eventList.push([event, uid]);
				nickName.set(uid, nick);
				break;
			case 'Leave':
				eventList.push([event, uid]);
				break;
			case 'Change':
				nickName.set(uid, nick);
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
