# Architecture Rules

- Keep sensor, network, visualization, and data processing concerns separated by directory.
- Keep credentials and local deployment details out of tracked files.
- Prefer shared topic constants over duplicated MQTT topic strings.
- Treat OTA support and MQTT behavior as operationally sensitive paths.
- Do not rewrite generated `doc/` content by hand.
