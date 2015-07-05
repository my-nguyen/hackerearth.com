# the position of the last man standing is that at the greatest power of 2
# (e.g. 2, 4, 8, 16, 32, 64, etc) that is smaller than or equal to n. For example,
# if n is 31 then last-man-standing position is 2**4 or 16. If n is 32 then
# that position is 2**5 or 32.
def process n
  i = 1
  while (2**i <= n)
    i += 1
  end
  n == 2**(i-1)
end

gets.to_i.times do
  puts(process(gets.to_i) ? "Yes" : "No")
end
