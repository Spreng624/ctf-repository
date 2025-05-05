import moon

# help(moon)
print(moon.xor_crypt(moon.SEED, bytes.fromhex(moon.TARGET_HEX)))
# print("I tried my best, to live an ordinary life.")
# print("But I hope you can look up and see the moonlight through reverse engineering on the streets full of sixpence.")

# user_input = input("Enter your flag: ").strip()

# result, error = moon.check_flag(user_input)

# if error:
#     print("Error.")
# elif result:
#     print("I think you have found the right way.")
# else:
#     print("You seem to be lost.")
