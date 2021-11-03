rand_max = 10
rand_min = 0
array_size = 10

function sort(array)
  local curr
  local j

  -- # is the length operator
  for i = 1, #array do
    curr = array[i]
    j = i - 1

    --[[
      While we have a previous element and our current element is less than the element 
      currently being iterated over
    --]]
    while j >= 0 and curr < array[j] do
      -- Set the next element to be the current element. i.e. shift right
      array[j + 1] = array[j]
      j = j - 1
    end

    -- Set the next element to be the current element
    array[j + 1] = curr
  end
end

function main()
  local array = {}
  math.randomseed(os.time())

  io.write("The original array is: [ ")
  for i = 0, array_size - 1 do
    array[i] = math.random(rand_min, rand_max) % (rand_max - rand_min + 1) + rand_min
    
    if i == (array_size - 1) then
      print(string.format("%d ]", array[i]))
    else
      io.write(string.format("%d, ", array[i]))
    end
  end

  sort(array)

  io.write("The sorted array is: [ ")
  for i = 0, array_size - 1 do
    if i == (array_size - 1) then
      print(string.format("%d ]", array[i]))
    else
      io.write(string.format("%d, ", array[i]))
    end
  end
end

main()
