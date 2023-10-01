class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        lines = [[words[0]]]
        for word in words[1:]:
            last_line = lines[-1]
            num_words = len(last_line)
            assert num_words >= 1

            min_line_len = sum(map(len, last_line)) + num_words - 1
            if min_line_len + len(word) + 1 <= maxWidth:
                last_line.append(word)
            else:
                lines.append([word])

        justified = []
        for line in lines[:-1]:
            text_len = sum(map(len, line))
            assert len(line) >= 1
            if len(line) == 1:
                s = line[0].ljust(maxWidth)
            else:
                num_spaces = maxWidth - text_len
                num_space_per_word = num_spaces // (len(line) - 1)
                extra_spaces = num_spaces % (len(line) - 1)
                s = line[0]
                for word in line[1:]:
                    num_spaces = num_space_per_word
                    if extra_spaces > 0:
                        extra_spaces -= 1
                        num_spaces += 1
                    s += " " * num_spaces + word
                assert len(s) == maxWidth
            # print(text_len, line, s)
            justified.append(s)
        justified.append(" ".join(lines[-1]).ljust(maxWidth))

        return justified