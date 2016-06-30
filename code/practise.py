
def output(data , format = "text"):

	output_func = getaatr(statsout,"output_%s" % format , statsout.output_text)
	return output_func(data)