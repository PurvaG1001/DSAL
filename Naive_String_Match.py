def naive_string_match(text, pattern):
    n = len(text)
    m = len(pattern)
    indices = []    # to store all matching positions

    # Loop over all possible starting positions in text
    for i in range(n - m + 1):
        match = True

        # Compare each character of pattern with substring in text
        for j in range(m):
            if text[i + j] != pattern[j]:
                match = False
                break

        # If no mismatch was found, record the index
        if match:
            indices.append(i)

    return indices   # return all positions where pattern occurs


# Example usage of the function
if __name__ == "__main__":

    text = "ababcabcabababd"
    pattern = "abab"

    result = naive_string_match(text, pattern)

    print("Pattern found at indices:", result)
