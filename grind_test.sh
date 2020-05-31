#!/usr/bin/env bash

main() {
  local target="$1"
  if [ -z "$target" ]; then
    echo "No target specified."
    exit 1
  fi

  local log_file="$2"
  if [ -z "$log_file" ]; then
    echo "No log file specified."
    exit 1
  fi

  echo valgrind --leak-check=full --track-origins=yes --log-file=\"$log_file\" \"$target\"
  if valgrind --leak-check=full --track-origins=yes --log-file="$log_file" "$target"; then
    local exit_ok="1"
  else
    local exit_ok=""
  fi

  local no_leaks=$(grep -i -e 'in use at exit: 0 bytes' "$log_file")
  local no_errors=$(grep -i -e 'ERROR SUMMARY: 0 errors' "$log_file")
  local rtld_failed=$(grep -i -e 'dl_rtld_map.*failed' "$log_file")
  local is_incons=$(grep -i -e 'Inconsistency' "$log_file")

  local is_err=""
  if [ -n "$is_incons" ]; then
    local is_err="1"
  fi

  if [ -n "$rtld_assertion" ]; then
    local is_err="1"
  fi

  if [ -z "$no_leaks" ]; then
    local is_err="1"
  fi

  if [ -z "$no_errors" ]; then
    local is_err="1"
  fi

  if [ "$is_err" == "1" ]; then
    cat "$log_file"
    exit 1;
  fi

  if [ -z "$exit_ok" ]; then
    exit 1;
  fi
}

main "$1" "$2"
