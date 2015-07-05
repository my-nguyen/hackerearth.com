def process(url)
  vowels = "aeiou"
  substring = ""
  # leave the starting "www." and trailing ".com" out of the url
  4.upto(url.length-5) do |idx|
    # retain the non-vowel characters
    if !vowels.include?(url[idx])
      substring << url[idx]
    end
    idx += 1
  end
  # append the ".com" to substring and return substring
  substring << ".com"
end

gets.to_i.times do
  url = gets.chomp
  puts("#{process(url).length}/#{url.length}")
end
