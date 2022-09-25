from curses.ascii import isalnum, isalpha


def shift_letter(letter: str, unit: int) -> str:
    start_letter = 'A' if letter == letter.upper() else 'a'
    start_ascii_value = ord(start_letter)
    shifted_range: int = (ord(letter) - start_ascii_value + unit) % 26
    return chr(start_ascii_value + shifted_range)


ctf_msg = [
    char for char in "arkg_gvzr_V'yy_gel_2_ebhaqf_bs_ebg13_uJdSftmh"]
print('ctf_msg = ', ctf_msg)
new_flag = ''.join([shift_letter(x, 13) if isalpha(x) else x for x in ctf_msg])
print("new_flag = ", new_flag)
print('len(new_flag) = ', len(new_flag))
