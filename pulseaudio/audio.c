
#include <stdio.h>
#include <unistd.h>
#include <pulse/simple.h>
#include <fcntl.h>

int main()
{
  char *file_content[400000];
  int myfd = open("output.wav", O_RDONLY);

  read(myfd, file_content, sizeof(file_content));

  close(myfd);

  pa_simple *simple = NULL;
  pa_sample_spec ss;
  ss.format = PA_SAMPLE_S16LE;
  ss.rate = 48000;
  ss.channels = 2;

  simple = pa_simple_new(NULL, "Audio Playback", PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, NULL);

  pa_simple_write(simple, file_content, sizeof(file_content), NULL);

  pa_simple_drain(simple, NULL);

  pa_simple_free(simple);

  return 0;
}