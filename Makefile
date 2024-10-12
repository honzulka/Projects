PROCESSING_PATH = /opt/processing-4.3
PROJ1_SKETCH = project_1

proj1:
	sudo $(PROCESSING_PATH)/processing-java --sketch=$(PROJ1_SKETCH) --run

.PHONY: proj1 