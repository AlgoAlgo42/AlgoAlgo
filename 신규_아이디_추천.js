const solution = (new_id) => {
	const id = new_id
		.toLowerCase()
		.replace(/[^\w-.]/g, '') // ^ -> 아닌것,  w -> 영어 소문자, 숫자, 언더스코어, _ -> -, . -> _
		.replace(/\.{2,}/g, '.') // {2,} -> 2개 이상
		.replace(/^\.|\.$/g, '') // ^ -> 처음, . -> 끝
		.padEnd(1, 'a') // 끝에 a 붙이기
		.slice(0, 15) // 15글자 자르기
		.replace(/^\.|\.$/g, ''); // ^ -> 처음, . -> 끝
	return id.padEnd(3, id[id.length - 1]); // 3글자 이하면 끝에 마지막 글자 붙이기
};
