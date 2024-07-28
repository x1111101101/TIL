# Schedule tasks with WorkManager
## Background work with WorkManager
This codelab covers WorkManager, a backwards compatible, flexible, and simple library for deferrable background work. WorkManager is the recommended task scheduler on Android for deferrable work, with a guarantee to execute.
- WorkManager
- Opportunistic execution
Classes
- Worker, CoroutineWorker
- WorkRequest
- WorkManager
### Create BlurWorker
``` kotlin
package com.example.bluromatic.workers

import androidx.work.CoroutineWorker
import androidx.work.WorkerParameters
import android.content.Context
import android.graphics.BitmapFactory
import android.util.Log
import com.example.bluromatic.DELAY_TIME_MILLIS
import com.example.bluromatic.R
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.delay
import kotlinx.coroutines.withContext

private const val TAG = "BlurWorker"
class BlurWorker(ctx: Context, params: WorkerParameters) : CoroutineWorker(ctx, params) {

    override suspend fun doWork(): Result {
        makeStatusNotification(
            applicationContext.resources.getString(R.string.blurring_image),
            applicationContext
        )

        return withContext(Dispatchers.IO) {
            return@withContext try {
                val picture = BitmapFactory.decodeResource(
                    applicationContext.resources,
                    R.drawable.android_cupcake
                )
                // This is an utility function added to emulate slower work.
                delay(DELAY_TIME_MILLIS)
                val output = blurBitmap(picture, 1)
                val outputUri = writeBitmapToFile(applicationContext, output)

                makeStatusNotification(
                    "Output is $outputUri",
                    applicationContext
                )
                Result.success()
            } catch (throwable: Throwable) {
                Log.e(
                    TAG,
                    applicationContext.resources.getString(R.string.error_applying_blur),
                    throwable
                )
                Result.failure()
            }
        }
    }
}
```

### Update WorkManagerBluromaticRepository
