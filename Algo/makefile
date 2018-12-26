# If the first argument is "comp"...
ifeq (comp,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "comp"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

ifeq (exec,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "comp"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

.PHONY: comp exec
comp :
	gcc -o ./bin/$(RUN_ARGS) $(RUN_ARGS).c

exec : comp
	./bin/$(RUN_ARGS)
