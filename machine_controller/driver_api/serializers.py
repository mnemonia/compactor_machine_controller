from rest_framework import serializers

from .models import Param


class ParamSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Param
        fields = ['id', 'param_id', 'index', 'label', 'value', 'timestamp']
        read_only_fields = ['id', 'param_id', 'index', 'label']
