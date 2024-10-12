def lzw_compress(input: str) -> list[int]:
	output = []
	dict = {
		"A": 1,
		"B": 2,
		"C": 3,
	}
	dict_count = 3

	i = 0
	while i < len(input):
		current_string = input[i]

		while i + 1 < len(input) and (current_string + input[i + 1]) in dict:
			current_string += input[i + 1]
			i += 1

		output.append(dict[current_string])
		
		if i + 1 < len(input):
			dict_count += 1
			dict[current_string + input[i + 1]] = dict_count

		i += 1

	return output

if __name__ == "__main__":
	compressed = lzw_compress("ABABABAACAACCBBAAAAAAAAA")
	print(compressed)
