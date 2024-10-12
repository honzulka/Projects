PROCESSING_PATH = /opt/processing-4.3
SKETCH = project_1

proj1:
	sudo $(PROCESSING_PATH)/processing-java --sketch=$(SKETCH) --run

.PHONY: proj1 