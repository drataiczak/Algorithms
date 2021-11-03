rand_max = 10
rand_min = 0
array_size = 10

function merge(array, leftBound, mid, rightBound)
  local leftSize = mid - leftBound + 1
  local rightSize = rightBound - mid
  local l = {}
  local r = {}

  for i = 1, leftSize do
    l[i] = array[leftBound + i - 1]
  end

  for i = 1, rightSize do
    r[i] = array[mid + i]
  end

  local i = 1
  local j = 1

  -- for k = left to k = right
  for k = leftBound, rightBound do
    -- if left <= right, array[k] = left, else array[k] = right
    -- increment i or j respectively
    if l[i]  <= r[j] then
      array[k] = l[i]
      i = i + 1
    else
      array[k] = r[j]
      j = j + 1
    end
  end 
end

function sort(array)
  -- # is the length operator
  for i = 0, #array do
    for j = i + 1, #array do
      if array[i] > array[j] then
        temp = array[i]

        array[i] = array[j]
        array[j] = temp
      end
    end
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
