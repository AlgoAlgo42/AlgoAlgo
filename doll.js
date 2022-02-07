function solution(board, moves) {
	var answer = 0;
	let line = [];
	moves.forEach((col) => {
		col -= 1;
		for (let i = 0, len = board.length; i < len; i++) {
			if (board[i][col] !== 0) {
				const lineLen = line.length;
				if (lineLen !== 0 && line[lineLen - 1] === board[i][col]) {
					line.pop();
					answer += 2;
				} else {
					line.push(board[i][col]);
				}
				board[i][col] = 0;
				break;
			}
		}
	});
	return answer;
}
